//employ.cpp
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
unsigned long long passed=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,j;
	unsigned long long sum=0;
	string s;
	vector<unsigned long long> h;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>j;
		p.push_back(j);
	}
	stable_sort(h,h+n);
	for(int i=0;i<n-2;i++){
		if(n-passed>=m){
			j=n-passed;
			sum=i+1;
			while(j){
				sum*=i+1;
				sum%=998244353ULL;
				j--;
			}
		}
		else if(h[i]>passed || s[i]==0) passed++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//The life is too short,and I like use python.