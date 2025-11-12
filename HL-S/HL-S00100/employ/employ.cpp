#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >>n>>m;
	string t;
	cin >>t;
	int nan[1000]={};
	for(int i=0;i<t.length(),i++){
		nan[i]=t[i];
	}
	int q[1000]={};
	q[0]=nan[0];
	for(int i=1;i<t.length(),i++){
		q[i]=q[i-1]+nan[i];
	}
	int people[1000]={};
	for(int i=0;i<n;i++) cin >>people[i];
	sort(people,people+n-1);
	int index=0;
	for(int i=0;i<t.length();i++){
		for(int j=0;j<n;j++){
			if(people[j]>=nan[i]&&j>=m){
				index=j;
		}	
	}
	cout <<(1+n-index)*(n-index)/2;
	return 0;
}