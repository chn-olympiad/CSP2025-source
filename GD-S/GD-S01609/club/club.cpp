#include<bits/stdc++.h>
using namespace std;
struct type{
	int scr,name;
}maxn[50002];
bool cmp(type a,type b){
		return a.scr>b.scr;
	}
long long a[50002],b[50002],c[50002],mem_a=0,mem_b=0,mem_c=0,ans=0;
int main(){
	//freopen("club.in ","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			maxn[i].scr=max(max(a[i],b[i]),c[i]);
			if(a[i]>max(b[i],c[i])) maxn[i].name=1;
			else if(b[i]>max(a[i],c[i])) maxn[i].name=2;
			else maxn[i].name=3;
		}
		sort(maxn,maxn+n,cmp);
		for(int i=0;i<n;i++){
			ans=0;
			if(maxn[i].name==1){
				if(mem_a<n/2){
					mem_a+=1;
					ans+=maxn[i].scr; 
				}
				else{
					if(b[i]>c[i]){
						maxn[i].name=(mem_b<n/2?2:3);
						maxn[i].scr=(mem_b<n/2?b[i]:c[i]);
					}
					else{
						maxn[i].name=(mem_c<n/2?3:2);
						maxn[i].scr=(mem_c<n/2?c[i]:b[i]);
					}
					i--;
				}
			}
			else if(maxn[i].name==2){
				if(mem_b<n/2){
					mem_b+=1;
					ans+=maxn[i].scr; 
				}
				else{
					if(a[i]>c[i]){
						maxn[i].name=(mem_a<n/2?1:3);
						maxn[i].scr=(mem_a<n/2?a[i]:c[i]);
					}
					else{
						maxn[i].name=(mem_c<n/2?3:1);
						maxn[i].scr=(mem_c<n/2?c[i]:a[i]);
					}
					i--;
				}
			}
			else{
				if(mem_c<n/2){
					mem_c+=1;
					ans+=maxn[i].scr; 
				}
				else{
					if(a[i]>b[i]){
						maxn[i].name=(mem_a<n/2?1:2);
						maxn[i].scr=(mem_a<n/2?a[i]:b[i]);
					}
					else{
						maxn[i].name=(mem_b<n/2?2:1);
						maxn[i].scr=(mem_a<n/2?b[i]:a[i]);
					}
					i--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

