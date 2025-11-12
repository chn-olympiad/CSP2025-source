#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b){
	return a.first<b.first;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k;
	scanf("%d %d", &n, &k);
	int a[n]={};
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	vector<pair<int, int>> b;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=a[i];
			for(int z=i+1;z<=j;z++){
				sum^=a[z];
			}
			if (sum==k) b.push_back(pair<int, int>(i, j));
		}
	}
	sort(b.begin(), b.end(), compare);
	int cnt=b.size();
	for(size_t i=0;i<b.size();i++){
		if(b[i].second>=b[i+1].first) {i++;cnt--;}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}