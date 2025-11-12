#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Club{
	int m[5];
	int max;
	int ma;
	int ch;
};
bool fun(Club a,Club b){
	return a.ch>b.ch;
}
int main(){
	freopen("club.in","i",stdin);
	freopen("club.out","o",stdout);
	int T=0;
	cin>>T;
	for(int g=0;g<T;g++){
		int n=0;
		long long bu[5]={},zong=0;
		vector<Club>a;
		cin>>n;
		for(int i=0;i<n;i++){
			Club t={};
			cin>>t.m[0]>>t.m[1]>>t.m[2];
			t.max=max(t.m[0],max(t.m[1],t.m[2]));
			t.ch=t.m[1]-t.m[0];
			if(t.ch<0){
				t.ch*=-1;
			}
			if(t.m[2]-t.m[1]<0){
				t.ch+=t.m[1]-t.m[2];
			}else{
				t.ch+=t.m[2]-t.m[1];
			}
			if(t.m[2]-t.m[0]<0){
				t.ch+=t.m[0]-t.m[2];
			}else{
				t.ch+=t.m[2]-t.m[0];
			}
			a.push_back(t);
    	}
    	sort(a.begin(),a.end(),fun);
    	for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(a[i].m[j]==a[i].max && bu[j]<n/2){
					bu[j]++;
					zong+=a[i].m[j];
				}else if(a[i].m[j]==a[i].max && bu[j]>=n/2){
					int l=0,u=0;
					for(int k=0;k<3;k++){
						if(k==j){
							continue;
						}
						if(l<a[i].m[k]){
							l=a[i].m[k];
							u=k;
						}
					}
					if(bu[u]>=n/2){
						u=3-u-j;
					}
					zong+=l;
					bu[u]++;
				}
			}
		}
    	cout<<zong;
	}
	
	
	
	
	
	
	
	return 0;
}
