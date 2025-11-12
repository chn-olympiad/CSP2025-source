#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long begin,end,size;
};
bool cmp(stu x,stu y){
	return x.end<y.end;
}
	long long n,m,ans=0;
	vector <long long> in;
	//vector <long long> a,b;
	vector <stu> den;
long long gemin(long long x,long long y){
	if(x==y)return in[x];
	long long an=in[x] ^ in[x+1];
	for(int i=x+2;i<=y;i++){
		an=an ^ in[i];
	}
	return an;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//cout<<(2 ^ 1 ^ 0)<<endl;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long kkk;
		cin>>kkk;
		in.push_back(kkk);
	}
	//cout<<"AAA"<<gemin(0,0)<<endl;
	for(long long begin=0;begin<n;begin++){
		for(long long end=begin;end<n;end++){
			if(gemin(begin,end)==m){
				//ans++;
				stu jl;
				jl.begin=begin;
				jl.end=end;
				jl.size=end-begin;
				den.push_back(jl);
				//cout<<begin<<' '<<end<<endl;;
			}
		}
	}
	sort(den.begin(),den.end(),cmp);
	for(long long i=0,end=0;i<den.end()-den.begin();i++){
		if(den[i].begin>end){
			end=den[i].end;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
