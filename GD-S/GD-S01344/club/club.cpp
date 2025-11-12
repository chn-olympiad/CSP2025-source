#include<bits/stdc++.h>
using namespace std;
struct b{
	int d,z;
};
struct r{
	b a[4]={0};
};
bool cmd1(b a1,b b1){
	return a1.z>b1.z;
}
bool cmd2(r a1,r b1){
	return (a1.a[1].z-a1.a[2].z)>(b1.a[1].z-b1.a[2].z);
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int sum=0;
		r s[50000]={0};
		int b[4]={0};
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=3;l++){
				cin>>s[j].a[l].z;
				s[j].a[l].d=l;
			}
			sort(s[j].a+1,s[j].a+4,cmd1);
			
		}
		sort(s+1,s+n+1,cmd2);
		for(int j=1;j<=n;j++){
			
			if(b[s[j].a[1].d]<n/2){
				if(b[s[j].a[1].d]+1>=n/2&&b[s[j+1].a[2].d]<n/2&&s[j].a[1].z+s[j+1].a[1].z<s[j].a[1].z+s[j+1].a[1].z&&j+1<=n&&s[j].a[2].d!=s[j+1].a[1].d){
					sum+=s[j].a[1].z+s[j+1].a[2].z;
					b[s[j].a[2].d]++;b[s[j+1].a[1].d]++;
					j++;
					continue; 
				}
				sum+=s[j].a[1].z;
				b[s[j].a[1].d]++;	
			}
			else if(b[s[j].a[2].d]<n/2){
				if(b[s[j].a[2].d]+1>=n/2&&b[s[j+1].a[3].d]<n/2&&s[j].a[2].z+s[j+1].a[2].z<s[j].a[2].z+s[j+1].a[2].z&&j+1<=n&&s[j].a[3].d!=s[j+1].a[2].d){
					sum+=s[j].a[2].z+s[j+1].a[3].z;
					b[s[j].a[3].d]++;b[s[j+1].a[2].d]++;
					j++;
					continue; 
				}
				sum+=s[j].a[2].z;
				b[s[j].a[2].d]++;	
			}
			else{
				sum+=s[j].a[3].z;
				b[s[j].a[3].d]++;	
			}
			
		}
		cout<<sum<<endl;
		
	}
	
	
	
	fclose(stdin);
	fclose(stdout); 
} 
