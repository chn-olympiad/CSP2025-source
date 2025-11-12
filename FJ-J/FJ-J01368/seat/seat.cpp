#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node{
	int num,id;
}a[N];
bool cmp(node aa,node bb){
	if(aa.num==bb.num)return aa.id<bb.id;
	else return aa.num>bb.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int pm;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			pm=i;
			break;
		}
	}
	int lin=(pm-1)/n+1,cor=pm%n;
	if(cor==0)cor=m;
	if(lin%2==1)cout<<lin<<" "<<cor;
	else cout<<lin<<" "<<n-cor+1;
	return 0;
} 
