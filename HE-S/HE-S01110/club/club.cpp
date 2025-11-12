#include<bits/stdc++.h>
using namespace std;
long long n,t,club1,club2,club3,ans=0;
long long a[100005][5];
long long changed1[100005],changed2[100005],changed3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int text=0;text<t;text++){
		cin>>n;
		ans=0;club1=0;club2=0;club3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				club1++;
				ans+=a[i][1];
				changed1[club1]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				club2++;
				ans+=a[i][2];
				changed2[club2]=a[i][2]-max(a[i][1],a[i][3]);
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				club3++;
				ans+=a[i][3];
				changed3[club3]=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		
		if(club1>n/2){
			sort(changed1+1,changed1+club1+1);
			for(int i=1;i<=club1-n/2;i++) ans-=changed1[i];
		}
		else if(club2>n/2){
			sort(changed2+1,changed2+club2+1);
			for(int i=1;i<=club2-n/2;i++) ans-=changed2[i];
		}
		else if(club3>n/2){
			sort(changed3+1,changed3+n+1);
			for(int i=1;i<=club3-n/2;i++) ans-=changed3[i];
		} 
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
