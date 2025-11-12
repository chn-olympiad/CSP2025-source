#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c; 
int cnt_a,cnt_b,cnt_c;
int ccnt_a,ccnt_b,ccnt_c;
long long ans=0;
int aa[100005],bb[100005],cc[100005];
int x,y,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int n=0;
	for(int i=1;i<=t;i++){
		cin >> n;
		for(int j=1;j<=n;j++){
			cin >> a >> b >> c;
			if(max(max(a,b),c)==a){
				if(b==0&&c==0){
					aa[i]=a;
					ccnt_a++;
				}
				else{
					cnt_a++;
					ans+=a;
				}
			}
			if(max(max(a,b),c)==b){
				if(a==0&&c==0){
					bb[i]=b;
					ccnt_b++;
				}
				else{
					cnt_b++;
					ans+=b;
				} 
			}
			if(max(max(a,b),c)==c){
				if(b==0&&a==0){
					cc[i]=c;
					ccnt_c++;
				}
				else{
					cnt_c++;
					ans+=c;
				}
			}
		}
		
		sort(aa,aa+ccnt_a+1);
		sort(bb,bb+ccnt_b+1);
		sort(cc,cc+ccnt_c+1);
		
		for(int i=ccnt_a;i>ccnt_a/2+1;i--) x+=aa[i];
		for(int i=ccnt_b;i>ccnt_b/2+1;i--) y+=bb[i];
		for(int i=ccnt_c;i>ccnt_c/2+1;i--) z+=cc[i];
		
		if(cnt_a<=n/2&&cnt_b<=n/2&&cnt_c<=n/2&&ccnt_a==0&&ccnt_b==0&&ccnt_c==0){
			cout << ans << '\n';
		}
		
		else{ //if(ccnt_a<=n/2&&ccnt_b<=n/2&&ccnt_c<=n/2){
			cout << max(max(x+ans+n/2,y+ans+n/2),z+ans+n/2) << '\n';
		}
		
		for(int i=1;i<=100005;i++){
			aa[i]=0;
			bb[i]=0;
			cc[i]=0;
		}
		cnt_a=0,cnt_b=0,cnt_c=0; 
		ans=0;
		ccnt_a=0,ccnt_b=0,ccnt_c=0;
	}
	return 0;
} 
