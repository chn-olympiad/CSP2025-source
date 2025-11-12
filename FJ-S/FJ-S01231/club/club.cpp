#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Student{
	int firstBi=0;
	int secondBi=0;
	int firstW=0;
	int secondW=0;
};

bool cmpStudent(Student a,Student b){
	return a.firstW-a.secondW > b.firstW-b.secondW;
}

int solve(){
	int n,tmp1,tmp2,tmp3,ans=0;
	Student tempS;
	cin>>n;
	vector<Student> students;
	for(int i=0;i<n;i++){
		cin>>tmp1>>tmp2>>tmp3;
		//---
		if(tmp1>tmp2){
			if(tmp1>tmp3){
				tempS.firstBi=1;
				tempS.firstW=tmp1;
				if(tmp2>tmp3){
					tempS.secondBi=2;
					tempS.secondW=tmp2;
				}else{
					tempS.secondBi=3;
					tempS.secondW=tmp3;
				}
			}else{
				tempS.firstBi=3;
				tempS.firstW=tmp3;
				if(tmp1>tmp2){
					tempS.secondBi=1;
					tempS.secondW=tmp1;
				}else{
					tempS.secondBi=2;
					tempS.secondW=tmp2;
				}
			}
		}else{
			if(tmp2>tmp3){
				tempS.firstBi=2;
				tempS.firstW=tmp2;
				if(tmp1>tmp3){
					tempS.secondBi=1;
					tempS.secondW=tmp1;
				}else{
					tempS.secondBi=3;
					tempS.secondW=tmp3;
				}
			}else{
				tempS.firstBi=3;
				tempS.firstW=tmp3;
				if(tmp1>tmp2){
					tempS.secondBi=1;
					tempS.secondW=tmp1;
				}else{
					tempS.secondBi=2;
					tempS.secondW=tmp2;
				}
			}
		}
		//---
		students.push_back(tempS);
	}
	sort(students.begin(),students.end(),cmpStudent);
	const int SIZ = n/2;
	int grpsiz[4] = {0,0,0,0};
	
	for(int i=0;i<n;i++){
		if(grpsiz[students[i].firstBi]<SIZ){
			ans+=students[i].firstW;
			grpsiz[students[i].firstBi]++;
		}else{
			ans+=students[i].secondW;
			grpsiz[students[i].secondBi]++;
		}
	}
	
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<solve()<<endl;
	}
}
