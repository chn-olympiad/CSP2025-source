#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=2e5+10;
int n,k,a[maxn],cnt,sum=1;

struct s{
	int l,r;
}list[maxn];

bool cmp(s m,s n){
	if(m.r<n.r) return 1;
	if(m.r>n.r) return 0;
	return m.l<n.l;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((a[r]^a[l-1])==k){
				list[cnt].l=l;
				list[cnt].r=r;
				cnt++;
			}
		}
	}
	 
	sort(list,list+cnt,cmp);
	
	int nextr=list[0].r;
	for(int i=1;i<cnt;i++)
		if(list[i].l>nextr){
			nextr=list[i].r;
			sum++;
		}
		
	cout<<sum;
	
	return 0;
}
