#include<bits/stdc++.h>
using namespace std;
int shuzu=500005;
bool cmp(int a,int b){
	return a>b;
	}
//void paixu(pair<int,int> a,pair<int,int> b,pair<int,int> c,int j){
//	pair<int,int> arr[3]={a,b,c};
//	sort(arr,arr+3,cmp);
//	pt1m[j]=arr[0];
//	pt2m[j]=arr[1];
//	pt3m[j]=arr[2];
	//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[6];
	for(int i=0;i<t;i++){
		cin>>n[i];
		vector<int> pt1(shuzu),pt2(shuzu),pt3(shuzu);
		for(int j=0;j<n[i];j++){
			cin>>pt1[j];
			cin>>pt2[j];
			cin>>pt3[j];
			}
		int sum=0;
		int nk=n[i]/2;
		sort(pt1.begin(),pt1.end(),cmp);
		for(int j=0;j<nk;j++){
					sum+=pt1[j];
				}
		cout<<sum<<endl;
	}
	return 0;
	}
