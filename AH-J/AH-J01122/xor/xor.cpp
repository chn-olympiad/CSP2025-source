#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
struct I{
	int l,r;
};
vector<I> v;
inline int X(int a,int b){
	string x="";
	while(a){
		x+=a%2+'0';
		a/=2;
	}
	string y="";
	while(b){
		y+=b%2+'0';
		b/=2;
	}
	int t=max(x.size(),y.size());
	while(int(x.size())<t){
		x+='0';
	}
	while(int(y.size())<t){
		y+='0';
	}
	int cnt=0;
	for(int i=t-1;i>=0;i--){
		if(x[i]!=y[i]){
			cnt=cnt*2+1;
		}
		else cnt*=2;
	}
	return cnt;
}
bool cmp(I i1,I i2){
	if(i1.l!=i2.l) return i1.l<i2.l;
	else return i1.r<i2.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=X(a[i],b[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=X(b[i-1],b[j]);
			if(t==k){
				I x;
				x.l=i;
				x.r=j;
				v.push_back(x);
			}
		}
	}
	if(v.size()==0){
		cout<<0;
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
	int cnt=0;
	int l=0,r=0;
	int f=0;
	for(auto x:v){
		if(l==0){
			if(x.l>r or(x.l>f and x.r<r)){
				l=x.l;
				r=x.r;
			}
		}
		else if(x.r>r){
			cnt++;
			f=l;
			l=0;
			if(x.l>r){
				l=x.l,r=x.r;
			}
		}
		else{
			l=x.l,r=x.r;
		}
	}
	if(l!=0) cnt++;
	cout<<cnt;
	return 0;
}
