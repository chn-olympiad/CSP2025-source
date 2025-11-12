#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e4;
struct stu{
	int x,y;
	int s;
	bool operator<(const stu &rhs)const{
		return s>rhs.s;
	}
}a[N];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i].s;
	}
	int q=a[1].s;
	sort(a+1,a+num+1);
	for(int i=1;i<=num;i++){
		if(a[i].s==q) q=i;
	}
	//cout<<q;
	int p=1;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>0;i--){
				//cout<<j<<" "<<i<<" ";
				a[p].x=j;
				a[p].y=i;
				p++;
				if(p>q)break;
			}
		}else{
			for(int i=1;i<=n;i++){
				//cout<<j<<" "<<i<<" ";
				a[p].x=j;
				a[p].y=i;
				p++;
				if(p>q)break;
			}
		}
	}
	//for(int i=1;i<=num;i++){
	cout<<a[q].x<<" "<<a[q].y<<endl;
	//}
	return 0;
}
//2 2 99 100 97 98
