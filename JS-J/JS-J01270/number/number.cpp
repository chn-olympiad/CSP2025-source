#include<bits/stdc++.h>
using namespace std;
int a[11];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>s;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch>='0'&&ch<='9')a[ch-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++)cout<<i;
    }
    return 0;
}
//15min, 100pts maybe

//Lately I've been I've been losing sleep
//Dreaming about the things that we could be
//But baby I've been I've been praying hard
//Say no more counting dollars
//We'll be counting stars
//I see this life like a swinging vine
//Swing my heart cross the line
//In my face is flashing signs
//Seek it out and you shall find
//I'm old but I'm not that old
//I'm young but I'm not that bold
//I don't think the world is sold
//On' just doing what we told
//I-I-I-I feel something so right when doing the wrong thing
//I-I-I-I feel something so wrong when doing the right thing
//I couldn't lie couldn't lie couldn't lie
//Every thing that kills me makes me feels alive
//Lately I've been I've been losing sleep
//Dreaming about the things that we could be
//But baby I've been I've been praying hard
//Say no more counting dollars
//We'll be counting stars
//Lately I've been I've been losing sleep
//Dreaming about the things that we could be
//But baby I've been I've been praying hard
//Say no more counting dollars
//We'll be counting stars
//Yeah we'll be counting stars
//I feel your love and I feel it burn
//Down this river every turn
//Hope is our four-letter word
//Take that money watch it burn
//I'm old but I'm not that old
//I'm young but I'm not that bold
//I don't think the world is sold
//On' just doing what we told
//I-I-I-I feel something so wrong when doing the right thing
//I couldn't lie couldn't lie couldn't lie
//Every thing that drowns me makes me wanna fly
//Lately I've been I've been losing sleep
//Dreaming about the things that we could be
//But baby I've been I've been praying hard
//Say no more counting dollars
//We'll be counting stars
//Lately I've been I've been losing sleep
//Dreaming about the things that we could be
//But baby I've been I've been praying hard
//Say no more counting dollars
//We'll be counting stars
//Yeah we'll be counting stars
