#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
class Person{
public:
	ll total,ml,x,y;
};
ll n,m;
vector<Person> xs;
bool cmp(Person a,Person b){
	return a.total>b.total;
}
void putin()
{
	cin>>n>>m;
	xs.resize(n*m);
	for(auto&f:xs) cin>>f.total;
	for(ll i=0;i<n*m;i++){
		cin>>xs[i].total;
		xs[i].ml=i;
	}
	sort(xs.begin(),xs.end(),cmp);
}
void chuli()
{
	ll xx=1,yy=1;
	for(auto &f:xs){
		f.x=xx,f.y=yy;
		if(yy%2){
			if(xx==n)yy++;
			else xx++;
		}
		else{
			if(xx==1) yy++;
			else xx--;
		}
	}
}
void putout(){
	for(auto f:xs)
		if(f.ml==0) cout<<f.y<<" "<<f.x<<endl;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	putin();
	chuli();
	putout();
	return 0;
}