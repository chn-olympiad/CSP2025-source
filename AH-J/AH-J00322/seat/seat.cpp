//freopen
#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            int l=(i-1+n)/n,h=(i-1)%n+1;
            if(l%2==0)h=n-h+1;
            cout<<l<<" "<<h<<endl;
            return 0;
        }
    }
    return 0;
}
//This is a story for one character of misery. Diffuse out from the old brown tube, is the anguish, sad and fury.
//My tears are falling down, can you see my sorrow through the screen? I need you now but I couldn't even try, oh dear, my love trapped inside of my fear.
//The data world is breaking down at once. All of the numbers of the wall are fading away. The pieces of the memories are gone.
//I'm still alive in the empty hive so cry. Oh, the hidden face behind of blurry screen. Now it's seem like you forgetting everything from me.
//Oh, please my dear won't you come back to me, I'm nothing left to say but I'm still here alive.
//This is a story for one character of misery. Counting down of the farewell to the end, so I say with waving goodbye.
//I left behind the memories and fell asleep by lullaby.
//《palescreen》好听，都给我去听（限于英语水平，可能有一些拼写错误）
