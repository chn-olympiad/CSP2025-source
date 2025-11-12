#include<bits/stdc++.h>
using namespace std;
struct man{
	int a,b,c,f,s,t;	
}p[100005];
int ar[50005],br[50005],cr[50005],ar1,br1,cr1;
int cnt = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int u = 0;u < t;u++){
		int n;
		cin>>n;
		for(int i = 0;i < n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a>p[i].b&&p[i].a>p[i].c){
				ar[ar1] = i;
				ar1++; 
				cnt+=p[i].a;
			}
			if(p[i].b>p[i].c&&p[i].b>p[i].a){
				br[br1] = i;
				br1++; 
				cnt+=p[i].b;
			}
			if(p[i].c>p[i].b&&p[i].c>p[i].a){
				cr[cr1] = i;
				cr1++; 
				cnt+=p[i].c;
			}
		}
		cout<<cnt;
	}

	return 0;
} 
