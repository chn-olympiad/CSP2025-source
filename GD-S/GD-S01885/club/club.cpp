#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,t,s,w,ans=0;
struct aa{
	int a;
	int b;
	int c;
	int maxx;
}aq[N];
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>aq[i].a>>aq[i].b>>aq[i].c;
			aq[i].maxx=max(max(aq[i].a,aq[i].b),aq[i].c);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(aq[i].maxx>aq[j].maxx){
					swap(aq[i],aq[j]);
				}	
			}
		}
		
	}
	return 0;
} 
