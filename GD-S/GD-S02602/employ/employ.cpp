#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m,c[maxn],p[maxn],res;
char s[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int fal=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0')fal++;
				else if(fal>=c[p[i]])fal++;
			}
			if(n-fal>=m)res++;
		}while(next_permutation(p+1,p+n+1));
		cout<<res;
	}
	
}
