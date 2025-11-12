#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,si,f,flag;
struct doge{
	int grade,id;
}a[10000];
int cmp(doge x,doge y){
	if(x.grade!=y.grade) return x.grade>y.grade;
	return x.id<y.id;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	si=n*m;
	for(int i=1;i<=si;i++){
		cin>>a[i].grade;
		a[i].id=i;
	}
	sort(a+1,a+si+1,cmp);
	for(int i=1;i<=si;i++){
		if(a[i].id==1) {
			flag=i;
			break;
		}
	}
	f=flag/n+1;
	flag%=n;
	if(flag==0){
		flag=n;
		f--;
	}
	if(f%2==0) flag=n-flag+1;
 	cout<<f<<" "<<flag;
 	return 0;
}	 
