#include<bits/stdc++.h>
using namespace std;
int t=0;
int tt=1;
int nm;
struct tset{
	int c;//成绩
	int h;//行
	int l;//列
}a[1000010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i].c;
		}
		tt=a[1].c;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i].c>a[j].c){
				nm=a[i].c;
				a[i].c=a[j].c;
				a[j].c=nm;
			}
		}
	}		
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				a[t].h=i;
				a[t].l=j;
				t++;
				//cout<<"T="<<m<<endl;
			}
		}
		else{
			for(int j=m;j>0;j--){
				a[t].h=i;
				a[t].l=j;
				t++;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
			if(a[i].c==tt){
				cout<<a[i].l<<' '<<a[i].h;
				break;
			}	
		}
	//	for(int i=1;i<=n*m;i++){
	//			cout<<a[i].c<<' ';
				
	//		}	
		
		//cout<<' '<<9a[tt].h<<' '<<a[tt].l;
	//for(int i=1;i<n*m;i++){
	//	cout<<a[i].c<<endl;
	//}
	return 0;
}
