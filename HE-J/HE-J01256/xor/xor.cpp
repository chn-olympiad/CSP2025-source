#include <bits/stdc++.h>
using namespace std;
long long n,k;
vector<long long> a;
struct are{
	int bh;
	int l,r;
	vector<int> chqj;
};
vector<are> ans1;
bool xors(int l,int r){
	int s=a[l];
	for(int i=l+1;i<=r;i++){
		s^=a[i];
	}
	if(s==k){
		return true;
	}
	return false;
}
int check(are &a,int side){ 
	int l=a.l;
	int r=a.r;
	for(int i=0;i<ans1.size();i++){
		if(i!=side){
			are s;
			s.l=ans1[i].l;
			s.r=ans1[i].r;
			s.bh=ans1[i].bh;
			if((s.l<=r&&s.r>=r)||(s.l<=l&&s.r>=l)||(s.l>=l&&s.r<=r)||(s.l<=l&&s.r>=r)){
				a.chqj.push_back(s.bh);
			}
		}
	}
	
}
bool check1(vector<are> ans){
	bool s=false;
	for(int i=0;i<ans.size();i++){
		if(ans[i].chqj.size()!=0){
			s=true;
		}
	}
	return s;
}
bool check3(vector<int> c,int t){
	for(int i=0;i<c.size();i++){
		if(c[i]==t){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a.push_back(0);
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		a.push_back(s);
	}
	int pos=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xors(i,j)){
				ans++;
				are d;
				d.l=i;
				d.r=j;
				d.bh=pos;
				pos++;
				ans1.push_back(d);
			}
		}
	}
	for(int i=0;i<ans1.size();i++){
		check(ans1[i],i);
	}
	while(check1(ans1)){
		int imax=0;
		int xb=0;
		int bh4=0;
		for(int i=0;i<ans1.size();i++){
			if(imax < ans1[i].chqj.size()){
				imax=ans1[i].chqj.size();
				xb=i;
				bh4=ans1[i].bh;
			}
		}
		ans1.erase(ans1.begin()+xb);
		for(int i=0;i<ans1.size();i++){
			if(check3(ans1[i].chqj,bh4)){
				int nn=0;
				for(int j=0;j<ans1[i].chqj.size();j++){
					if(ans1[i].chqj[j]==bh4){
						nn=j;
						break;
					}
				}
				ans1[i].chqj.erase(ans1[i].chqj.begin()+nn);
			}
		}
	}
	cout<<ans1.size()<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
