#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10005;i++)a[i]=-1;
	for(int i=1;i<10005;i++)cin>>a[i];
	sort(a+1,a+10005,cmp);
	for(int i=1;i<=10005;i++){
		if(a[i]!=-1)cout<<a[i];
	}
	return 0;
}