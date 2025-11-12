#include<bits/stdc++.h>
using namespace std;
long long t;
struct cy{
	long long a1;
	long long b1;
	long long c1;
	long long id;
}a[100005];
bool cmp(cy l,cy r){
		return l.a1>r.a1;
};
bool cmy(cy l,cy r){
		return l.b1>r.b1;
};
bool cms(cy l,cy r){
	return l.c1>r.c1;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans1=0,ans2=0,ans3=0,cnt1=0,cnt2=0,cnt3=0,n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].b1>>a[i].c1;
			a[i].id=i;
			if(a[i].a1>=a[i].b1&&a[i].a1>=a[i].c1){
				ans1+=a[i].a1;
				cnt1++;
			}
			else if(a[i].b1>=a[i].c1){
				ans2+=a[i].b1;
				cnt2++;
			}
			else{
				ans3+=a[i].c1;
				cnt3++;
			}
		}
		if(cnt1>n/2){
			ans1=0;
			sort(a+1,a+n+1,cmp);
		    for(int i=1;i<=n/2;i++){
			    ans1+=a[i].a1;
			    //cout<<a[i].a1<<endl;
			    a[i].id=0;
		    }
		    ans2=0;
		    ans3=0;
		    for(int i=1;i<=n;i++){
			    if(a[i].id!=0){
				    if(a[i].b1>=a[i].c1){
					    ans2+=a[i].b1;
				    }
				    else{
				    	ans3+=a[i].c1;
					}
			    }
		    }
		}
		else if(cnt2>n/2){
			ans2=0;
			sort(a+1,a+n+1,cmy);
		    for(int i=1;i<=n/2;i++){
			    ans2+=a[i].b1;
			    //cout<<a[i].b1<<endl;
			    a[i].id=0;
		    }
		    ans1==0;
		    ans3==0;
		    for(int i=1;i<=n;i++){
		    	if(a[i].id!=0){
		    		if(a[i].c1>=a[i].a1){
		    			ans3+=a[i].c1;
					}
					else{
						ans1+=a[i].a1;
					}
				}
			}
		}
		else if(cnt3>n/2){
			ans3=0;
			sort(a+1,a+n+1,cms);
		    for(int i=1;i<=n/2;i++){
			    ans3+=a[i].c1;
			    a[i].id=0;
		    }
		    ans1==0;
		    ans2==0;
		    for(int i=1;i<=n;i++){
		    	if(a[i].id!=0){
		    		if(a[i].a1>=a[i].b1){
		    			ans1+=a[i].a1;
					}
					else{
						ans2+=a[i].b1;
					}
				}
			}
		}
		cout<<ans1+ans2+ans3<<endl;
	}
	return 0;
}
