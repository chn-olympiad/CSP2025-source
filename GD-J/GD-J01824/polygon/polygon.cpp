#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
ull stick(vector<int> gg){
	if(gg.size()==0)
		return 0;
	if(gg.size()==3)
	{
		if(gg.at(2)*2<(
		gg.at(0)+gg.at(1)+gg.at(2)
		))
			return 1;
	}
	return 0; 
} 
int main() {
	FILE* in=freopen("polygon.in","r",stdin);
	FILE* out=freopen("polygon.out","w",stdout);
	int nn=0;
	long long cho=0;
	vector<int> gg;
	int s=gg.size();
	cin>>nn;
	for(int n=0;n!=nn;++n){
		int buff;
		cin>>buff;
		gg.push_back(buff);
	}
	sort(gg.begin(),gg.end());
	cho=stick(gg);
	cout<<cho;
	fclose(in);
	fclose(out);
} 
