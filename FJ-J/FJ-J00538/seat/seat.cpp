#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],s,h=1,l=1;
bool flag=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];		
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			cout<<l<<" "<<h;
			break;
		}
		if(flag==0){
			h++;
		}else{
			h--;
		}
		if(h>n){
			l++;
			h=n;
			flag=1;
		}
		if(h<1){
			l++;
			h=1;
			flag=0;
		}
	}
	return 0;
} 
