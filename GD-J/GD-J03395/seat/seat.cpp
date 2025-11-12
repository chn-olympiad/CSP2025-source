#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu{
	int grade;
	int index;
	bool b; 
};
stu a[10009];
bool cmp(stu x,stu y){
	return x.grade>y.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].grade;
		a[i].b = false;
		//a[i].index = i;
	}
	a[1].b =true;
	sort(a+1,a+1+n*m,cmp);
	int g;
	for(int i=1;i<=n*m;i++){
		a[i].index = i;
		//cout<<a[i].grade<<" "<<a[i].index<<endl;
		if(a[i].b ==1) g= a[i].index;
	}
	int h;
	if(g%n>0){
		h = g/n+1;
	}
	else
		h = g/n;
	if(h%2==1){
		int len=1;
		for(int i=h*n-n+1;i<=5*3;i++,len++){
			if(g==i){
				cout<<h<<" "<<len;
				break;
			}
		}
	}
	if(h%2==0){
	
		int len=1;
		for(int i=h*n;i>=h*n-n+1;i--,len++){
			if(g==i){
				cout<<h<<" "<<len;
				break;
			}
		}
	}
	return 0;
}
