#include<bits/stdc++.h>
using namespace std;
int a[1000];
int r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int size=n*m;
	for(int i=1;i<=size;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+size+1,cmp);
	int cnt=0;
	for(int i=1;i<=size;i++){
		cnt++;
		if(a[i]==r){
			break;
		}
	}
	int lie=cnt/n;
	cnt%=n;
	if(cnt!=0){
		lie++;
	}
	if(lie%2!=0){
		cout<<lie<<" ";
		if(cnt==0){
			cout<<m<<endl;
		}else{
			cout<<cnt<<endl;
		}
	}
	else{
		cout<<lie<<" ";
		if(cnt==0){
			cout<<1;
		}else{
			cout<<n-cnt+1<<endl;
		}
	}
	return 0;
}
