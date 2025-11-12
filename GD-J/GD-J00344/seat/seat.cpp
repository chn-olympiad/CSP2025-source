#include<bits/stdc++.h>
using namespace std;
int a[103],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	int s=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) s++;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,t=1;
	for(int i=1;i<s;i++){
		if(t){
			if(y==m){
				x+=1; t=0;
				continue;
			}
			else y+=1;
		}
		else{
			if(y==1){
				x+=1; t=1;
				continue;
			}
			else y-=1;
		}
	}
	cout<<x<<' '<<y;
	freopen("seat.out","w",stdout);
	return 0;
} 
