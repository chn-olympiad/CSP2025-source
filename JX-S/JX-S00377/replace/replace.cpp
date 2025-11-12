#include<bits/stdc++.h>
using namespace std;
bool b[7];
string o;
string s[10];
void game(){
    cout<<"stranger: This game is called Rusan Gun."<<endl<<"A gun has five empty hole and a bullet,we shot at ourself every turn untill someone die."<<endl;
    cin>>o;
    cout<<"You: Why I trust you?"<<endl;
    cin>>o;
    cout<<endl<<"The stranger becomes a demon."<<endl;
    cin>>o;
    cout<<"Now you can trust me."<<endl;
    cin>>o;
    puts("");puts("");puts("");puts("");puts("");
    cout<<"Demon: who gets first?"<<endl;
    cin>>s[0];
    if(s[0]=="You"){
        int i=0;
        while(++i){
            if(i%2==1)cout<<"Demon's turn"<<endl;
            else cout<<"Your's turn"<<endl;
            if(i%2==1&&b[i]==1){
                cout<<"BOOM!"<<endl;
                cout<<"YOU WIN!"<<endl;
                cout<<"You have lots of money and everything you want."<<endl;
                return ;
            }
            else if(i%2==0&&b[i]==1){
                cout<<"BOOM!"<<endl;
                cout<<"YOU DEAD."<<endl;
                cout<<"Game over"<<endl;
                return ;
            }
            else cout<<"Nothing happened"<<endl;
            cin>>o;
        }
    }
    else{
        int i=0;
        while(++i){
            if(i%2==1)cout<<"Your's turn"<<endl;
            else cout<<"Demon's turn"<<endl;
            if(i%2==1&&b[i]==1){
                cout<<"BOOM!"<<endl;
                cout<<"YOU DEAD."<<endl;
                cout<<"Game over"<<endl;
                return ;
            }
            if(i%2==0&&b[i]==1){
                cout<<"BOOM!"<<endl;
                cout<<"YOU WIN!"<<endl;
                cout<<"You have lots of money and everything you want."<<endl;
                return ;
            }
            else cout<<"Ka.   Nothing happened"<<endl;
            cin>>o;
        }
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    srand(time(NULL));
    int a=rand();
    a%=6;
    if(a==0)a=6;
    b[a]=1;
    int r=0;
    while(1){
        r++;
        cout<<"Hello"<<endl;

        cin>>s[0];
        cout<<"stranger: Do you want to play with me?"<<endl;cout<<"You: ";
        cin>>s[0];
        if(s[0]=="Yes")game();
        else{
            cout<<"stranger: What do you want?"<<endl;
            int i=1;bool f=0;cout<<"You: ";
            cin>>s[0];
            if(s[0]=="Fuckyou!"||s[0]=="Sonofbitch"||s[0]=="Goaway!")f=1;
            if(f==1){
                cout<<"stranger: You will die soon cause what you speak!"<<endl;
                cin>>o;
                cout<<endl<<"The stranger becomes angry and turn to a demon."<<endl;
                //cout<<"You: ";
                //cin>>s[0];
                cout<<"Demon: Go to the hell!!!"<<endl;
                cout<<"No one can save you"<<endl<<"You dead."<<endl;
                cout<<endl<<"Game over"<<endl;
                return 0;
            }
            cout<<"stranger: I can give it to you if you play this game with me."<<endl;
            cin>>o;
            cout<<"You: How to play? I will play it with you."<<endl;
            game();
            break;
        }
    }
    return 0;
}
