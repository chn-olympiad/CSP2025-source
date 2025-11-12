#include<bits/stdc++.h>
using namespace std;
bool c(int q,int e){
	return q> e;
}
const int N = 1e7+5;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	int kb;
	cin>>n>>m;
	int a[N];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	kb=a[1];
	sort(a+1,a+m*n+1,c);
	for(int i=1;i<=m*n;i++){
		bool d =1;
		if(d==1){
			q++;
		}else{
			q--;
		}
		if(d==1){
			if(q==n){
				e++;
				
			}else(){
				
			}
		}
	}
	return 0;
} 
