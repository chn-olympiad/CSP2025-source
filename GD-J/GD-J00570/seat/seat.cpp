#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,score;
}a[105];
int n,m;
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int index=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			index=i;
			break;
		}
	}
	int hang,lie;
	if(index%n==0){
		lie=index/n;
	}else{
		lie=index/n+1;
	}
	cout << lie<<" ";
	int p;
	if(index%n==0){
		p=n;
	}else{
		p=index%n;
	}
	if(lie%2==1){
		hang=p;
	}else{
		hang=n+1-p;
	}
	cout << hang;
	return 0;
} 
