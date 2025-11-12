#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n,k;
int a[500005],sa[500005];
struct point{
	int l,r;
	bool operator <(const point o)const{
		if(r!=o.r) return r<o.r;
		return l<o.l;
	}
}p[100005];
string toB(int x){
	string s = "";
	while(x){
		int b=x%2;
		x/=2;
		s = s+(char)(b+'0');
	}
	return s;
}
int toO(string s){
	int ans=0,base=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') ans+=base;
		base*=2;
	}
	return ans;
}
int Xor(int x,int y){
	string xB = toB(x);
	string yB = toB(y);
	string s="";
	for(int i=0;i<max(xB.size(),yB.size());i++){
		if(i>xB.size()-1) s = s + yB[i];
		else if(i>yB.size()-1) s = s + xB[i];
		else if(xB[i]==yB[i]) s = s + '0';
		else s = s + '1'; 
	}
	return toO(s);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ind=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		    int val=a[i]; 
			for(int k=i+1;k<=j;k++)
				val = Xor(val,a[k]);
			if(val==k){
				ind++;
				p[ind].l = i;
				p[ind].r = j;
			}
		}
	}
	sort(p+1,p+ind+1);
	int end = p[1].r,cnt=1; 
	for(int i=2;i<=ind;i++){
		if(end<p[i].l){
			cnt++;
			end = p[i].r;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
