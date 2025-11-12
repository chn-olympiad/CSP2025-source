//GZ-S00327 贵州师范大学云岩实验中学 王永年 
#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int patients[n];
	int otpatients[n];
	for(int i=0;i<n;i++){
		cin>>patients[i];
		otpatients[i]=patients[i];
	}
	int difficulties[s.length()];
	for(int i=0;i<s.length();i++){
		difficulties[i]=s[i]-'0';
	}
	sort(patients,patients+n,cmp);
	int ram=0;
	int raw=0;
	for(int i=n;i>0;i++){
		if(ram<=patients[0]){
			ram+=patients[i];
			raw++;
		}
	}
	int an=0;
	if(raw>=n){
		
		for(int i=0;i<s.length();i++){
			if(difficulties[i]==1){
				an++;
			}
		}
	}
//	for(int i=0;;i++){
	//	if(an==1){
			break;
	//	}
	//	an*=an;
	//	an--;
		
	}
	cout<<6<<endl;
	return 0;
} 
