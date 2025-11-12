#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct StringReplace{
    string base;
    string replace;
};

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    uint n,q;
    cin >> n >> q;
    vector<StringReplace> tp(n);
    for(StringReplace &p: tp){
        cin >> p.base >> p.replace;
    }
    while(q--){
        uint count = 0;
        string src, dst;
        cin >> src >> dst;

        for(StringReplace &p: tp){
            int pos = 0;
            while((pos = src.find(p.base, pos)) != string::npos){

                // cout << "Pos of " << p.base << " in " << src << ": " << pos << endl;

                // try to match

                uint replace_size = p.replace.size();
                /*
                uint src_size = src.size();
                string replaced(" ", src_size);

                for(uint i = 0; i < src.size(); i++){
                    if(i >= pos && i < pos + replace_size){
                        cout << "Replaced i: " << i << endl;
                        replaced[i] = p.replace[i-pos];
                    }else{
                        replaced[i] = src[i];
                    }
                }
                cout << "Replaced: " << replaced << endl;
                */

                bool always_equal = true;

                for(uint i = 0; i < src.size() && always_equal; i++){
                    if(i >= pos && i < pos + replace_size){
                        always_equal = p.replace[i-pos] == dst[i];
                    }else{
                        always_equal = src[i] == dst[i];
                    }
                }

                if(always_equal) count++;

                pos += replace_size;

            }
        }

        cout << count << endl;
    }
    
    return 0;
}