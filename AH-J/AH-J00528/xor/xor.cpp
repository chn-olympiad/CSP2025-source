#include<bits/stdc++.h>
using namespace std;
long long a[500009],n,q,ans,t,i,g;
long long dfs(long long number,long long x,long long y)
{
	if(number==y-x+1)return ans;
	long long p1[100009],p2[100009],k,j,i,s[100009];
	for(i=x;i<=y-number+1;i++){\
		k=0;
		for(j=i;j<=i+number-1;j++){
			while(s[i]!=0||a[j]!=0){
				k++;
				p1[k]=s[i]%10;
				s[i]/=10;
				p2[k]=a[i]%10;
				a[i]/=10;
			}
			for(i=1;i<=k;i++)cout<<a[i];
			cout<<"\n";
			for(i=1;i<=k;i++){
				if(p1[i]==p2[i]){
					s[i]=0;
				}else{
					s[i]++;
					j=i;
					while(s[j]!=1){
						s[j]=0;
						s[j+1]++;
						j++;
					}
				}	
				a[i]=0;		
			}	
		}
		long long o=1;
		for(i=1;i<=k;i++){
			s[i]=s[i-1]+s[i]*o;
			o*=2;
		}
		if(s[i]==q){
			ans++;
			if(i-x+1>number){
				dfs(number,x,i-x+1);
			}else if(y-i+1>number){
				dfs(number,y-i+1,y);
			}
		}
	}
	number++;
}
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>t;
		if(t==q){
			ans++;
			dfs(2,g+1,i-1);
			g=i;
		}else{
			while(t!=0){
				a[i]*=10;
				a[i]+=t%2;
				t=t/2;
			}
		}
	}
	dfs(2,g+1,n);
	cout<<ans;
	return 0;
}
