#include<bits/stdc++.h>
using namespace std;
int n,m,a[1145];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int h=a[1],l;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==h){
			l=i;
			break;
		}
	}
	int li,ri;
	if(l%n==0){
		li=l/n+1;
		ri=1;
	}else{
		li=l/n+1;
		ri=l%n;
	}
	if(li%2==0){
		cout<<li<<' '<<n-ri+1;
	}else{
		cout<<li<<' '<<ri;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
