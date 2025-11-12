#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long a;
	long long b;
	long long c;
};
stu a[1000000];
long long n,ans;
long long s[1000000];
int f(int k){
	long long i=1,j,t,l=0;
	long long b[n+1];
	i=1;
	while(i<=3){
		j=1;
		while(j<=n){
			b[j]=0;
			j++;
		}
		l=0;
		s[k]=i;
		if(k==n){
			/*cout<<18<<endl;
			j=1;
			while(j<=n){
				cout<<s[j]<<" ";
				j++;
			}
			cout<<endl;*/
			t=0;
			j=1;
			while(j<=n){
				b[s[j]]++;
				if(b[s[j]]>n/2){
					t=1;
					break;
				}
				j++;
			}
			if(t==0){
			//	cout<<37<<endl;
				j=1;
				while(j<=n){
					if(s[j]==1){
						l+=a[j].a;
					}
					else if(s[j]==2){
						l+=a[j].b;
					}
					else{
						l+=a[j].c;
					}
					j++;
				}
				if(l>ans){
					/*j=1;
					while(j<=n){
						cout<<s[j]<<" ";
						j++;
					}
					cout<<endl<<"&&&"<<" "<<l<<endl;*/
					ans=l;
				}
			}
		}
		else{
			f(k+1);
		}
		i++;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	long long j=1,i=1;
	while(j<=t){
		cin>>n;
		i=1;
		while(i<=n){
			cin>>a[i].a>>a[i].b>>a[i].c;
			i++;
		}
		f(1);
		cout<<ans<<endl;
		ans=0;
		j++;
	}
	return 0;
}
