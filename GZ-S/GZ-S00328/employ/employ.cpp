//GZ-S00328 贵阳市花溪区同为京学附属实验学校 王洪羿
#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],sum,outs;
string s;
int main(){
	cin>>n>>m;
	getline(cin,s);
	int ls=s.size();
	for(int i=0;i<n;i++){
		cin>>c[i];	//每个人的耐心程度 
	}
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++) swap(c[k],c[k+1]);
		for(int j=0;j<n;j++){
			if(s[j]==0){
				outs++;
			}else{
				if(c[j]>outs&&m>0){
					m--;
					sum++;
				}
			}
		}
	}
	cout<<sum/998244353;
	return 0;
}
