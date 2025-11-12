#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll t,n,ans,num1,num2,num3;
struct sub{
	ll a,b,c;
}x[N];
bool cmp(sub i,sub j){
	return max(i.b-i.a,i.c-i.a)>max(j.b-j.a,j.c-j.a);
}
vector<sub> x1,x2,x3;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,num1=0,num2=0,num3=0;
		x1.clear();
		x2.clear();
		x3.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c) ans+=x[i].a,num1++,x1.push_back(x[i]);
			else if(x[i].b>=x[i].c) ans+=x[i].b,num2++,x2.push_back(x[i]);
			else ans+=x[i].c,num3++,x3.push_back(x[i]);
		}
		if(num2>num1){
			swap(num1,num2);
			swap(x1,x2);
			ll ww=x1.size();
			for(int i=0;i<ww;i++){
				swap(x1[i].a,x1[i].b);
			}
		}
		if(num3>num1){
			swap(num1,num3);
			swap(x1,x3);
			ll ww=x1.size();
			for(int i=0;i<ww;i++){
				swap(x1[i].a,x1[i].c);
			}
		}
		if(num1<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		sort(x1.begin(),x1.end(),cmp);
		for(int i=0;i<num1-n/2;i++){
			ans+=max(x1[i].b-x1[i].a,x1[i].c-x1[i].a);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//chong gou shu
//segment tree
//zhuxi tree
//shu lian pou fen
//dp
//tan xin
//er fen
//zui duan lu
//tarjan
//shu de zhi jin/zhong xin
//topu
//stack
//queue
//priority_queue
//map
//bitset
//zi dian shu
//manacher
//KMP
//exgcd
//ju zhen
//fen kuai
//da biao
