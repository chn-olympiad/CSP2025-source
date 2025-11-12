#include<iostream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t,num,na=0,nb=0,nc=0,q;
	cin>>t;
	q=t;
	int x[100005];
	while(q--){
		int n,myd=0;
		cin>>n;
		num=n/2;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if((a>b && a>c) && na<num)na++;
			else if((b>a && b>c) && nb<num)nb++;
			else if((c>a && c>b) && nc<num)nc++;
		}
		int y=na+nb+nc;
		x[t-q]=y;
	}
	for(int i=0;i<t;i++) cout<<x[i]<<endl;
	return 0;
}
