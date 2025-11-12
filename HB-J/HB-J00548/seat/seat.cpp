#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,len,r;
	cin>>n>>m;
	len=n*m;
	int a[len];
	for(int i=0;i<len;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+len);
	for(int i=len-1,nowx=1,nowy=1;i>=0;i--){
		if(a[i]==r){
			cout<<nowy<<nowx;
			return 0;
		}
		if(nowy%2==1){
			if(nowx==n){
				nowy++;
				continue;
			}
			nowx++;
			continue;
		}
		else{
			if(nowx==1){
				nowy++;
				continue;
			}
			nowx--;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
