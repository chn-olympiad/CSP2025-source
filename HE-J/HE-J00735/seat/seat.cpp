#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,num;
int hang=1,lie=1,cnt;
struct node{
	int fen;
	int bian;
}a[N];
bool cmp(node xx,node yy){
	return xx.fen>yy.fen;
}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i].fen;
		a[i].bian=i;
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(a[i].bian==1){
			cout<<lie<<" "<<hang;
			return 0;
		}
		if(cnt==1){
			if(hang==1){
				lie++;
				cnt=0;
			}else{
				hang--;
			}
		}else{
			if(hang==n){
				lie++;
				cnt=1;
			}else{
				hang++;
			}
		}
	}
	
	return 0;
}
/*
2 2
98 99 100 97
2 2
99 100 97 98
*/
