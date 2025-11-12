#include<bits/stdc++.h>
using namespace std;
int n,aa[105];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>aa[i];
	}
	int d=aa[0];
	sort(aa,aa+(a*b),cmp);
	for(int i=0;i<a*b;i++){
//		cout<<aa[i]<<' ';
		if(aa[i]==d){
			d=i;
		}
	}
	d++;
//	int lie=(d+1)/(2*a),liec=d%(2*a);
//	lie*=2;liec++;
//	if(liec>a){
//		liec-=a;
//		liec=a-liec+1;
//		lie++;
//	}
//	cout<<lie<<' '<<liec;
//	int q=d/a,w=(d-1)%a+1;
//	if(d%a!=0){
//		q++;
//	}
//	if(q%2==0&&w!=1&&w!=a){
//		w=a-w+1;
//	}
//	cout<<q<<' '<<w;
	int dd=0;
	for(int i=1;i<=b;i++){
		if(i%2==1){
			for(int j=1;j<=a;j++){
				dd++;
				if(d==dd){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=a;j>=1;j--){
				dd++;
				if(dd==d){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
