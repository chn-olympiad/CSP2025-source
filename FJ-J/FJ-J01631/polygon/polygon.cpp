//polygon.cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[5000],n;
long long poly(int s,int c,vector<int> stick){
	long long sum=0,res=0;
	if(c==1){
		for(int i=s;i<=n-c;i++){
			stick.push_back(a[i]);
			for(int j=0;j<stick.size();j++){
				sum+=stick[j];
			}
			auto end=stick.end();
			advance(end,-1);
			stable_sort(stick.begin(),end);
			if(sum>*end) res++; 
			stick.pop_back();
		}
	}
	else{
		for(int i=s;i<=n-c;i++){
			stick.push_back(a[i]);
			res+=poly(i+1,c-1,stick)%998244353ULL;
			stick.pop_back();
		}
	}
	return res;
}
unsigned long long comp(int num){
	vector<int> sticks;
	long long res=0;
	for(int i=0;i<num;i++){
		res+=poly(i,num,sticks)%998244353ULL;
	}
	return res;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,cnt=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=3;i<=n;i++){
		cnt+=comp(i);
		cnt%=998244353ULL;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
