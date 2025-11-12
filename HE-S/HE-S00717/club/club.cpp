#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n;
int T;
struct node{
	int x,y,z;
};
bool cmpx(node a,node b){return a.x-max(a.y,a.z)<b.x-max(b.y,b.z);}
bool cmpy(node a,node b){return a.y-max(a.x,a.z)<b.y-max(b.x,b.z);}
bool cmpz(node a,node b){return a.z-max(a.x,b.y)<b.z-max(b.x,b.y);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		vector<node> a1,a2,a3;
		for(int i=1;i<=n;i++){
			int ai1,ai2,ai3;
			cin>>ai1>>ai2>>ai3;
			node ai={ai1,ai2,ai3};
		       	 if(ai1>=ai2&&ai1>=ai3) a1.push_back(ai);
			else if(ai2>=ai1&&ai2>=ai3) a2.push_back(ai);
			else if(ai3>=ai1&&ai3>=ai2) a3.push_back(ai);
		}
		int d=0;
		if(a1.size()>n/2){
			sort(a1.begin(),a1.end(),cmpx);
			d=a1.size()-n/2;
			for(int i=0;i<d;i++){
				if(a1[i].y==a1[i].z) if(a2.size()<=a3.size()) a2.push_back(a1[i]); else a3.push_back(a1[i]);
				if(a1[i].y>a1[i].z&&a2.size()>=n/2) a3.push_back(a1[i]);
				if(a1[i].y<a1[i].z&&a3.size()>=n/2) a2.push_back(a1[i]);
				if(a1[i].y>a1[i].z&&a2.size()<n/2)  a2.push_back(a1[i]);
				if(a1[i].y<a1[i].z&&a3.size()<n/2)  a3.push_back(a1[i]);
			}
			for(int i=0;i<d;i++) a1.erase(a1.begin());
		}else if(a2.size()>n/2){
			sort(a2.begin(),a2.end(),cmpy);
			d=a2.size()-n/2;
			for(int i=0;i<d;i++){
				if(a2[i].x==a2[i].z) if(a1.size()<=a3.size()) a1.push_back(a2[i]); else a3.push_back(a2[i]);
				if(a2[i].x>a2[i].z&&a1.size()>=n/2) a3.push_back(a2[i]);
				if(a2[i].x<a2[i].z&&a3.size()>=n/2) a1.push_back(a2[i]);
				if(a2[i].x>a2[i].z&&a1.size()<n/2)  a1.push_back(a2[i]);
				if(a2[i].x<a2[i].z&&a3.size()<n/2)  a3.push_back(a2[i]);
			}
			for(int i=0;i<d;i++) a2.erase(a2.begin());
		}else if(a3.size()>n/2){
			sort(a3.begin(),a3.end(),cmpz);
			d=a3.size()-n/2;
			for(int i=0;i<d;i++){
				if(a3[i].y==a3[i].z) if(a1.size()<=a2.size()) a1.push_back(a3[i]); else a2.push_back(a3[i]);
				if(a3[i].x>a3[i].y&&a1.size()>=n/2) a2.push_back(a3[i]);
				if(a3[i].x<a3[i].y&&a2.size()>=n/2) a1.push_back(a3[i]);
				if(a3[i].x>a3[i].y&&a1.size()<n/2)  a1.push_back(a3[i]);
				if(a3[i].x<a3[i].y&&a2.size()<n/2)  a2.push_back(a3[i]);
			}
			for(int i=0;i<d;i++) a3.erase(a3.begin());
		}
		long long ans=0;
		for(int i=0;i<a1.size();i++) ans+=a1[i].x;
		for(int i=0;i<a2.size();i++) ans+=a2[i].y;
		for(int i=0;i<a3.size();i++) ans+=a3[i].z;
		cout<<ans<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
