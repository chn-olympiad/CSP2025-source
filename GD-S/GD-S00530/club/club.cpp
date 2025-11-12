#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;
struct s{
	int pos;
	int val;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,maxval,j=3;
	cin>>n;
	bool judge[100005];
	int sum=0;
	s arr1[100005];
	s arr2[100005];
	s arr3[100005];
	for(int j=1;j<=n;j++){
		for(int i=1;i<=3;i++){
			cin>>arr1[i].val>>arr2[i].val>>arr3[i].val;
			arr1[i].pos = j;
			arr2[i].pos = j;
			arr3[i].pos = j;
		}
	}
//	sort(arr1,arr1+n);
//	sort(arr2,arr2+n);
//	sort(arr3,arr3+n);
//	if(judge[arr1[i].pos] != true){
//		sum += arr1[i].val;
//		judge[arr1[i].pos] = true;
//	} 
	return 0;
} 
