#include<iostream>
#include<windows.h>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<map>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	
	int ans=0;
	for(int i=0;i<n;i++){
		int h=0;
		int j=n-1;
		int s=0;
		bool p=1;
		while(h<=a[i]*2){
			if(j==-1){
				p=0;
				break;
			}
			h+=a[j--];
			s++;
			j--;
		}
		if(p==0){
			continue;
		}
//		int lian=1;
//		int duojian
//		for(int c=i+1;c<a.size();c++){
//			if(a[c]==a[c-1]){
//				lian++;
//			}
//			if(lian>s){
//				duojian++;
//			}
//		}
//		
//		int tans=1;
//		int tc=1;
//		for(int c=n-i-1-duojian;c>=1;c--){
//			tans*=c;
//			chut*=tc;
//			tc++;
//		}
//		tans/=chut;
		map<int,int> t;
		d(t,a,i+1);
//		for(int c=i+1;c<n;c++){
//			for()
//			t[a[c]]++;
//			
//		}
	}
	return 0;
}
