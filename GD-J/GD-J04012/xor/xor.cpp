//I'm Luogu UID 1049103 @Airbus_A380
//CCF Give me 1= Please I DON'T WANT TO AFO
//20251101 0931 No thoughts. Try special data.
/*
A: a[i]=1.
1^1=0.
       -> 1^1^1=0. 1^1^1^1=1. 
0^1=1.
so if k==0, the answer is n/2 because the parts are {1,1},{1,1},......
   if k==1, the answer is n   because the parts are {1},{1},......
   if k>1 , the answer is 0   because Can't find parts >1 in an arr with 1.
*/
//20251101 0944 Still no thoughts. Try BruteForce.
//20251101 1000 BF Test Data 5 WA. Ans 69 Out 9.
//20251101 1004 BF Test Data 5 WA. Ans 69 Out 26.
//20251101 1018 BF Test Data 5 Still WA.
//20251101 1018 BF Change thought.
//20251101 1031 BF Test Data 1 WA. Ans 2 Out 1.
//20251101 1031 BF Test Data 1 OK. Proceeding Test.
//20251101 1034 BF Test Data 5 WA. Ans 69 Out 68.
//20251101 1034 BF Test Data 5 WA. Ans 69 Out 67.
//20251101 1034 BF Test Data 5 WA. Ans 69 Out 68.
//20251101 1135 Coded SPD B.
//20251101 1137 SPD B Test Data 4 WA. Ans 63 Out 71.
//20251101 1142 SPD B Test Data 4 OK.
#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010];
bool vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	set<long long> st;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		st.insert(a[i]);
	}
	//SPD A
	if(a[1]==1&&st.size()==1){
		if(k==0) cout<<n/2<<endl;
		else if(k==1) cout<<n<<endl;
		else cout<<0<<endl;
		return 0;
	}
	//SPD B
	if(st.size()==2){
//		bool b[2];
		bool flag=false;
		for(auto a:st){
			if(a==0||a==1){
				flag=true;
			}else{
				flag=false;
				break;
			}
		}
		if(flag){
			long long ans=0;
			a[n+1]=-1;
			if(k==1){
				//find 1
				for(long long i=1;i<=n;i++){
					if(a[i]==1) ans++;
//					if(a[i]==0&&a[i+1]==0){
//						ans++;
//						i++;
//					}
				}
			}else if(k==0){
				for(long long i=1;i<=n;i++){
					if(a[i]==0) ans++;
					if(a[i]==1&&a[i+1]==1){
						ans++;
						i++;
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	//BF
	long long ans=0;
//	for(long long i=1;i<=n;i++){
//		if(a[i]==k){
//			vis[i]=true;
//			ans++;
//		}
//	}
//	cout<<ans<<endl;
//	for(long long l=1;l<=n;l++){
//		if(vis[l]==true) continue;
//		for(long long r=l+1;r<=n;r++){
//			if(vis[r]==true) break;
//			long long sum=a[l];
//			bool flag=false;
//			if(vis[l]==true){
//				flag=true;
//				continue;
//			}
//			for(long long i=l+1;i<=r;i++){
//				sum^=a[i];
//				if(vis[i]==true){
//					flag=true;
//					break;
//				}
//			}
//			if(flag) continue;
//			if(sum!=k) continue;
//			ans++;
//			for(long long i=l;i<=r;i++){
//				vis[i]=true;
//			}
////			
//			break;
//		}
//	}
//	cout<<ans<<endl;
	for(long long len=1;len<=n;len++){
		for(long long l=1;l+len-1<=n;l++){
			long long r=l+len-1;
			if(vis[l]) continue;
			if(vis[r]){
				l=r;
				continue;
			}
			long long sum=0;
			bool flag=false;
			for(long long i=l;i<=r;i++){
				sum^=a[i];
				if(vis[i]){
					l=i;
					flag=true;
					break;
				} 
			} 
			if(flag||sum!=k)continue;
			for(long long i=l;i<=r;i++){
				vis[i]=true;
			} 
			ans++;
//			cout<<len<<' '<<l<<' '<<r<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
