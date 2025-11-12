#include<bits\stdc++.h>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int ar[12][12];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	
	vector<int> arr(n*m+1,0);
	for (int i=1;i<=n*m;i++)
		cin >> arr[i];
	int target=arr[1];
	sort(arr.begin(),arr.end(),cmp);
	int count=0;
	for (int i=1;i<=m;i++){
		for (int j=(i%2==1)?1:n;j>=1&&j<=n;count++){
			if (arr[count]==target) cout << i<< ' '<< j;
			if (i%2==1) j++;
			else j--;
		}
	}
	return 0;
}