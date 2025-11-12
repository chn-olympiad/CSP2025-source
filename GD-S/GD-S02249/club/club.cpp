#include<bits/stdc++.h>
using namespace std;
struct club{
	int cl1,cl2,cl3;
	void read(){
		cin>>cl1>>cl2>>cl3;
	}
}a[100005];
int a1,a2,a3,s1,s2,s3;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].read();
			if(a[i].cl1 >a[i].cl2&&a[i].cl1 >a[i].cl3){
				a1++;
				s1+=a[i].cl1;
			}
			else if(a[i].cl2 >a[i].cl1&&a[i].cl2 >a[i].cl3){
				a2++;
				s2+=a[i].cl2;
			}
			else{
				a3++;
				s3+=a[i].cl3;
			}
		}
		cout<<s1+s2+s3<<"\n";
		a1=0;
		a2=0;
		a3=0;
		s1=0;
		s2=0;
		s3=0;
	}
} 
