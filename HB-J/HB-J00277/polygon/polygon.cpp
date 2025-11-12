#include<bits/stdc++.h>
using namespace std;
const int akioi=998244353;
int n,a[5005],ans=0;
bool iskkkakioi(int kkkscore[],int t){
	int kkksum=0,kkkmax=0;
	for(int i=1;i<=t;i++){
		kkksum+=kkkscore[i];
		kkkmax=max(kkkmax,kkkscore[i]);
	}
	if(kkksum>kkkmax*2){
		return true;
	}else{
		return false;
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[5005];
	for(int p=3;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				b[j]=a[i+j];
			}
			if(iskkkakioi(b,p)){
				ans=(ans%akioi+1)%akioi;
			}
		}
	}
	cout<<ans%akioi;
	return 0;
}
/*CSP-J diary 	 
     * 08:36 T1 think can ac
	 * 08:48 T2 too EZ
	 * 08:50 T3 WHAT IS XOR??????(I ACTUALLY FORGETY IT,FK)
	 * 08:54 T3 dead-think
	 * 08:56 T4 DFS can be %40 (csp2024(3?) stick:please write things there)
	 * 08:59 T4 bingchaji->100%,but I forget it
	 * 09:00 T1 gogogo
	 * 09:01 eat a candy(
	 * 09:11 T1 ACCCCCCCCC [11min]
	 * 09:14 T1 BIGDATA kills my Editor....
	 * 09:16 T2 gogogo
	 * 09:32 T2 BOOOOOOOOOM shit
	 * 09:35 T2 find some incorrect,I have to think again
	 * 09:41 T2 I am SB because I forget i--
	 * 09:47 T2 BOOOOOOOOOM again
	 * 09:56 T2 I am blind that write % to /
	 * 09:58 T2 (x,y) x is done
	 * 10:02 T2 be ready!!
	 * 10:06 T2 discover a small mistake
	 * 10:08 T2 BIGDATA ac
	 * 10:10 T2 begin make data for test
	 * 10:17 T2 personal data WA [qwq]
	 * 10:28 T2 bad maybe be finding
	 * 10:40 go to WC
	 * 10:45 T2 I AM SBBBBBBBBBBB BECAUSE MY PERSONAL DATA IS INCORRECT!!!!!!! 
	            THAT WASTE ME 30 MINUTES!!! (WC is very useful)
	 * 10:48 T2 ACCCCCCCCCCC [92min]
	 * 10:49 eat candy again)
	 * 10:51 T3 GET OUT OF MY TEST!
	 * 10:52 T4 20%gogogo
	 * 11:00 T4 iskkkakioi ready
	 * 11:09 T4 so diffcult
	 * 11:13 T4 I maybe make an O(pow(n,5)) dfs...
	 * 11:17 T4 The 2025CSP-J is too EZ that I think my friends can AK but I can not 
	 * 11:20 T4 is hard so I decide to fish
	 * 11:29 T4	test WA and only left 30 min
	 * 11:30 Childrens,do you think I can AKCSP in 30 min?
	 * 11:34 T4 I want to jumping because my dfs is BOOOOOOOOM
	 * 11:45 T4 RP++
	 * 11:48 T4 my brain is dead so I do not want to write anything
	 * 11:50 ok my CSP-J trip can over
	 * 11:51 oh shit I need to have CSP-S in the afternoon
	 * 11:53 miku saigao
	 * 11:55 BYEBYE RUSSIA
BY HB-J00277*/
