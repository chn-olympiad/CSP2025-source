#include <bits/stdc++.h>
using namespace std;
struct Node{
	string s1,s2;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	Node arr[n],brr[m];
	for(int i=0;i<m;i++){
		cin>>brr[i].s1>>brr[i].s2;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i].s1>>arr[i].s2;
	}
	for(int i=0;i<m;i++){
		long long z=0;
		for(int j=0;j<n;j++){
			if(brr[i].s1.size()<arr[j].s1.size()){
				continue;
			} 
			if(brr[i].s1.find(arr[j].s1)>=0&&brr[i].s1.find(arr[j].s1)<=brr[i].s1.size()&&brr[i].s2.find(arr[j].s1)>=0&&brr[i].s2.find(arr[j].s1)<=brr[i].s2.size()){
				string a="";
				for(int f=0;f<brr[i].s1.find(arr[j].s1);f++){
					a=a+brr[i].s1[f];
				}
				a=a+arr[j].s2;
				for(int f=brr[i].s1.find(arr[j].s1)+arr[j].s1.size();f<brr[i].s1.size();f++){
					a=a+brr[i].s1[f];
				}
				if(a==brr[i].s2){
					z=z+1;
				}
			}
		}
		cout<<z<<endl;
	}
	return 0;
}
