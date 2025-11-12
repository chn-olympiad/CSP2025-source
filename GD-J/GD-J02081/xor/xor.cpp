//prefix ^?
//xia wo yi tiao wo hai yi wei 2^55 ne

#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int p[500005];
int ans,maxx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		p[i] = p[i-1] ^ a[i];
	}
	
	//if it is two lrs that are not crossing thats no as hard as i thought since S was mad
	//i only got to enter S last year and that was crazy
	//110 and 2=
	//its LOL that my J is 66.5 and my S is 70 in the first test
	//ha chi mi do nan bei lv dou
	for(int j = 1;j <= n;j ++){//fuck it p can start from any place that takes 35 
		for(int i = j;;){
			int t=i;
			while((p[t] ^ p[i-1]) != k){
				t++;
				if(t > n){
					break;
				}
			}
			//cout<<i<<" "<<t<<endl;
			ans ++;
			if(t > n) ans --;
			
			
		}		
		maxx = max(maxx,ans);
		ans = 0;
	}
	cout <<maxx;
}
//QwQ -> ?.? -> TxT -> X_X
/*`		_______


	10:13:
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!      !!!! !!!! !!!!!     !!! !!   !!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!! !!!!!!!!! !!!! !!!! !!!!!!!! !  !!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!      !!!! !!!! !!!! !!!!!!!!   !!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!! !!!!!!!!! !!!! !!!! !!!!!!!! !   !!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!! !!!!!!!!!!    !!!!!!     !!! !!!  !!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!     !!!!!!!     !!!!!!      !!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!! !!!!!!!!!!! !!!!!!!!!!!! !!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!! !!!!!!!!!!! !!!!!!!!!!!!     !!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!! !!!!!!!!!!! !!!!!!!!!!!! !!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!      !!!!!!      !!!!!! !!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WHY IS THIS THING ALWAYS LESS THAN THE RIGHT ANS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	11:54 OOOOOOOOOOOOHHHHHHHHH GOT PAST WITH xor5 CCF I LOVE YOU ~ PLEASE GIVE ME 400 PTS OR ILL HATE YOU 
	11:55 BYEBYE! SEE YOU IN S




 10:40 GIVE UP TO SOVLE THE PROBLEM
 11:28 BACK TO TRY AGAIN
11:52 TOTOLLY GIVEN UP ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ BNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
*if i got myself on TV , PLEASE tell me why my code couldnt past ORZ
I GUESS I SLEPT ON THE KEYBOARD BECAUSE THERE IS MANY RANDOM CHARS HERE
WELL OUCHENCHEN1 IS GOING TO CONTINUE SLEEPING

*/
