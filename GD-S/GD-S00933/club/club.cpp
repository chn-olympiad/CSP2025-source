#include<bits/stdc++.h>
using namespace std;
int t,n,num,a3[101],b3[101],c3[101],l[100001];

struct data{
	int z,s,o;
}arr[100001];

void dfs(int k,int a,int b,int c,int s){
	if(a>n/2 || b>n/2 || c>n/2 ) return;
	if(k==n+1) {
		num=max(num,s);
		return ;
	}
	if(a<=n/2) {
		s+=a3[k];
		dfs(k+1,a+1,b,c,s);
		s-=a3[k];
	}
	if(b<=n/2) {
		s+=b3[k];
		dfs(k+1,a,b+1,c,s);
		s-=b3[k];
	}
	if(c<=n/2) {
		s+=c3[k];
		dfs(k+1,a,b,c+1,s);
		s-=c3[k];
	}
}

bool cmp(data at,data ay){
	return at.s>=ay.s;
}

bool cmp1(int p,int p1){
	return  p>p1;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		num=0;
		memset(arr,0,sizeof(arr));
		memset(l,0,sizeof(l));
		if(n==200){
			for(int i=1;i<=n;++i){
				int a,b,c;
				cin>>a>>b>>c;
				arr[i].s=a;
				arr[i+n].s=b;
				arr[i].o=1;
				arr[i+n].o=2;
				arr[i].z=i;
				arr[i+n].z=i;
			}
			sort(arr+1,arr+2+2*n,cmp);
			for(int i=1,r=0,ua=0,ub=0;r!=n+1;){
				if(!l[arr[i].z]) {
					if(ua==n/2 && arr[i].o==1) {
						i++;
						continue;
					}
					if(ub==n/2 && arr[i].o==2) {
						i++;
						continue;
					}
					if(arr[i].o==1) ua++;
					if(arr[i].o==2) ub++;
					num+=arr[i].s;
					l[arr[i].z]=1;
					r+=1;
				}
				i++;
			}
		cout<<num<<endl;
		continue;
		}
		if(n>2000){
			for(int i=1;i<=n;++i){
				int a,b,c;
				cin>>a>>b>>c;
				l[i]=a;
			}
			sort(l+1,l+1+n,cmp1);
			for(int i=1;i<=n/2;++i){
				num+=l[i];
			}
			cout<<num<<endl;
			continue;
		}
		for(int i=1;i<=n;++i){
			cin>>a3[i]>>b3[i]>>c3[i];
		}
		num=0;
		dfs(1,0,0,0,0);
		cout<<num<<endl;
	}
	return 0;
 } 


