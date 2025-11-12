#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node{
	int score;bool flag;
}a[N];
int n,m;
bool cmp(node p,node q){
	return p.score>q.score;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;int h=n*m;
	for(int i=1;i<=h;i++){
		int x;cin>>x;
		a[i].score=x;a[i].flag=0;
	}a[1].flag=1;
	sort(a+1,a+h+1,cmp);
	for(int i=1;i<=h;i++){
		if(a[i].flag==1){
			int p,q;p=i/n;q=i%n;
			if(q==0){
				if(p%2==0){
					cout<<p<<" "<<1;
				}else{
					cout<<p<<" "<<n;
				}
			}else{
				if((p+1)%2==0){
					cout<<p+1<<" "<<n-q+1;
				}else{
					cout<<p+1<<" "<<q;
				}
			}
		}
	}return 0;
}