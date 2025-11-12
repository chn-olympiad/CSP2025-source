#include <bits/stdc++.h>
using namespace std;
int n,m,o[103],mm;//n->行 m->列 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>o[i];//a->列 b->行 
	mm=o[1];
	sort(o+1,o+1+n*m,cmp);
	for(int i=1,a=1,b=1;i<=n*m;i++){
		if(o[i]==mm){
			cout<<a<<' '<<b;
			return 0;
		}else{
			if(b>=1&&b<n&&a%2==1)b++;
			else if(b>1&&b<=n&&a%2==0)b--;
			else if(b==1&&a%2==0)a++;
			else if(b==n&&a%2==1)a++;
		}
	} 
	return 0;
}
