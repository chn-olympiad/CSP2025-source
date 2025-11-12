#include<bits/stdc++.h>
using namespace std;
struct student{
	int one;
	int two;
	int three;
};
bool cmp1(student x,student y){
	return x.one>y.one;
	if(x.one==y.one)return x.two>y.two;
}
bool cmp2(student x,student y){
	return x.two>y.two;
	if(x.two==y.two)return x.one>y.one;
}
bool cmp3(student x,student y){
	return x.three>y.three;
	if(x.three==y.three)return x.one>y.one;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		student a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i].one>>a[i].two>>a[i].three;
		}
		long long s1=0,s2=0,s3=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			s1+=a[i].one;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++){
			s2+=a[i].two;
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n/2;i++){
			s3+=a[i].three;
		}
		long long s=0;
		if(n==2){
			int b[3][4];
			for(int i=1;i<=2;i++){
				b[i][1]=a[i].one,b[i][2]=a[i].two,b[i][3]=a[i].three;
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j)s=max(b[1][i]+b[2][j],int(s));
				}
			}
			cout<<s<<endl;
			continue;
		}
		if(s1>=s2&&s1>=s3){
			s+=s1;
			sort(a+1,a+n+1,cmp1);
			for(int i=n/2+1;i<=n;i++){
				s+=max(a[i].two,a[i].three);
			}
		}
		else if(s2>=s1&&s2>=s3){
			s+=s2;
			sort(a+1,a+n+1,cmp2);
			for(int i=n/2+1;i<=n;i++){
				s+=max(a[i].one,a[i].three);
			}
		}
		else if(s3>=s1&&s3>=s2){
			s+=s3;
			sort(a+1,a+n+1,cmp3);
			for(int i=n/2+1;i<=n;i++){
				s+=max(a[i].one,a[i].two);
			}
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
