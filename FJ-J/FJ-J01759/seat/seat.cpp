#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+5,mod=1e9+7;
using namespace std;
struct node{
	int data,id;
	bool operator <(const node b)const{
		return data>b.data ;
	} 
}a[N];
int n,m,cnt,px=1,py=1;
bool d=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[++cnt].data ,a[cnt].id =i;
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		if(a[i].id ==1){
			cout<<py<<' '<<px;
			return 0;
		}
		if(d){
			if(px==n){
				py++;
				d=0; 
			}else{
				px++;
			}
		}else{
			if(px==1){
				py++;
				d=1;
			}else{
				px--;
			}
		}
	}
	return 0;
}
